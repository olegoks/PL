#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>


typedef char* DataType;

struct Vertex {

	DataType data_;
	struct Vertex* left_child_;
	struct Vertex* right_child_;

};

struct Vertex* new_vertex(DataType data) {

	struct Vertex* const new_vertex_ptr = (struct Vertex*)malloc(sizeof(struct Vertex));
	new_vertex_ptr->data_ = data;
	new_vertex_ptr->left_child_ = NULL;
	new_vertex_ptr->right_child_ = NULL;

	return new_vertex_ptr;
}

void add_data(struct Vertex* const root, DataType data) {

	if (data > root->data_) {

		if (root->left_child_ == NULL) root->left_child_ = new_vertex(data);
		else
			add_data(root->left_child_, data);

	}
	else {

		if (root->right_child_ == NULL) root->right_child_ = new_vertex(data);
		else
			add_data(root->right_child_, data);

	}

}


struct node_print_state_t {
	struct node_print_state_t* child_state;
	int printing_last_child;
};

struct node_print_state_t* _root_state = NULL;


void print_subtree(const struct Vertex* node) {

	struct node_print_state_t* parent_state;
	if (_root_state != NULL) {
		printf(" ");
		struct node_print_state_t* s = _root_state;
		while (s->child_state != NULL) {
			printf(s->printing_last_child ? "  " : "| ");
			s = s->child_state;
		}
		parent_state = s;
		printf(parent_state->printing_last_child ? "L" : "+");
	}
	else {
		parent_state = NULL;
	}
	printf(">%s\n", node->data_);

	if ((node->left_child_ != NULL) || (node->right_child_ != NULL)) { // åñëè åñòü äåòè
		struct node_print_state_t s;
		if (parent_state != NULL) {
			parent_state->child_state = &s;
		}
		else {
			_root_state = &s;
		}
		s.child_state = NULL;

		// ïå÷àòàåì äåòåé
		if (node->left_child_ != NULL) {
			s.printing_last_child = (node->right_child_ == NULL);
			print_subtree(node->left_child_);
		}
		if (node->right_child_ != NULL) {
			s.printing_last_child = 1;
			print_subtree(node->right_child_);
		}

		if (parent_state != NULL) {
			parent_state->child_state = NULL;
		}
		else {
			_root_state = NULL;
		}
	}
}




void prefix(struct Vertex* tree) {
	if (tree != NULL) { //Пока не встретится пустой узел
		printf("%s", tree->data_);
		prefix(tree->left_child_); //Рекурсивная функция для левого поддерева
		prefix(tree->right_child_); //Рекурсивная функция для правого поддерева
	}
}


void postfix(struct Vertex* tree) {
	if (tree != NULL) { //Пока не встретится пустой узел
		postfix(tree->left_child_); //Рекурсивная функция для левого поддерева
		postfix(tree->right_child_); //Рекурсивная функция для правого поддерева
		printf("%s", tree->data_);

	}
}
void print_tree(const struct Vertex* root) {

	if (root != NULL) {
		print_subtree(root);
	}

}

void DeleteBrackets(char** expression) {

	const unsigned int expr_len = strlen(*expression);

	const unsigned int last_index = expr_len- 1;
	static const char space = ' ';

	if (expr_len > 1) {

		if ((*expression)[0] == '(' && (*expression)[last_index] == ')')
		{
			(*expression)[last_index] = '\0';
			(*expression)++;

		}

	}

}

int FindOperator(char* const expression) {

	const unsigned int expr_len = strlen(expression);
	int brackets = 0;
	int first_prior = -1, second_prior = -1;

	for (size_t i = 0; i < expr_len; i++){

		const char symbol = expression[i];

		switch (symbol) {
		case '+': {

			if (first_prior == -1 && !brackets) {
				first_prior = i;
				return first_prior;
			}
		}
		case '-': {

			if (first_prior == -1 && !brackets) {
				first_prior = i;
				return first_prior;
			}
		}
		case '*': {

			if (second_prior == -1 && !brackets)
				second_prior = i;

			break;
		}
		case '/': {

			if (second_prior == -1 && !brackets)
				second_prior = i;

			break;
		}
		case '(': {

			brackets++;

			break;
		}
		case ')': {

			brackets--;

			break;
		}

		};
	}

	return second_prior;

}

void SomeFunction(struct Vertex* const tree, char* expression) {
	DeleteBrackets(&expression);
	int num = FindOperator(expression);
	if (num != -1) {

		char* some_ptr = (char*)malloc(sizeof(char) * 2);
		some_ptr[0] = expression[num];
		some_ptr[1] = '\0';
		tree->data_ = some_ptr;
 
		char* left = (char*) malloc(num + 1);

		for (size_t i = 0; i < num; i++)
			left[i] = expression[i];

		left[num] = '\0';
		const size_t expression_len = strlen(expression);
		char* right = (char*)malloc(expression_len - num);
		strcpy(right, expression + num + 1);

		tree->left_child_ = new_vertex((char*)malloc(sizeof(char) * 10));
		tree->right_child_ = new_vertex((char*)malloc(sizeof(char) * 10));

		SomeFunction(tree->left_child_, left);
		SomeFunction(tree->right_child_, right);
	}
	else {
		strcpy(tree->data_, expression);
	}
}

int main() {

	char input_expression[100]={'\0'};
	gets(input_expression);

	struct Vertex* const root = new_vertex(NULL);

	SomeFunction(root, input_expression);
	print_subtree(root);
	postfix(root);
	system("pause");
	return 0;
}