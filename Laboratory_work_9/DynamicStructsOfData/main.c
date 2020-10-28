#include <stdio.h>

typedef int DataType;

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
    printf(">%i\n", node->data_);

    if ((node->left_child_ != NULL) || (node->right_child_ != NULL)) { // если есть дети
        struct node_print_state_t s;
        if (parent_state != NULL) {
            parent_state->child_state = &s;
        }
        else {
            _root_state = &s;
        }
        s.child_state = NULL;

        // печатаем детей
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



void print_tree(const struct Vertex* root) {

    if (root != NULL) {
        print_subtree(root);
    }

}
unsigned int counter = 0;
void count_vertexs(const struct Vertex* node) {

    struct node_print_state_t* parent_state;
    if (_root_state != NULL) {
        //printf(" ");
        struct node_print_state_t* s = _root_state;
        while (s->child_state != NULL) {
            //printf(s->printing_last_child ? "  " : "| ");
            s = s->child_state;
        }
        parent_state = s;
        //printf(parent_state->printing_last_child ? "L" : "+");
    }
    else {
        parent_state = NULL;
    }
    counter++;//printf(">%i\n", node->data_);

    if ((node->left_child_ != NULL) || (node->right_child_ != NULL)) { // если есть дети
        struct node_print_state_t s;
        if (parent_state != NULL) {
            parent_state->child_state = &s;
        }
        else {
            _root_state = &s;
        }
        s.child_state = NULL;

        // печатаем детей
        if (node->left_child_ != NULL) {
            s.printing_last_child = (node->right_child_ == NULL);
            count_vertexs(node->left_child_);
        }
        if (node->right_child_ != NULL) {
            s.printing_last_child = 1;
            count_vertexs(node->right_child_);
        }

        if (parent_state != NULL) {
            parent_state->child_state = NULL;
        }
        else {

            _root_state = NULL;

        }
    }

}


void count_vertexs_1(const struct Vertex* node) {

    if ((node->left_child_ == NULL && node->right_child_ != NULL) || (node->left_child_ != NULL && node->right_child_ == NULL))counter++;

    struct node_print_state_t* parent_state;

    if (_root_state != NULL) {
        //printf(" ");
        struct node_print_state_t* s = _root_state;
        while (s->child_state != NULL) {
            //printf(s->printing_last_child ? "  " : "| ");
            s = s->child_state;
        }
        parent_state = s;
        //printf(parent_state->printing_last_child ? "L" : "+");
    }
    else {
        parent_state = NULL;
    }
    //printf(">%i\n", node->data_);

    if ((node->left_child_ != NULL) || (node->right_child_ != NULL)) { // если есть дети
       
    
        
        struct node_print_state_t s;
        if (parent_state != NULL) {
            parent_state->child_state = &s;
        }
        else {
            _root_state = &s;
        }
        s.child_state = NULL;

        // печатаем детей

        if (node->left_child_ != NULL) {
            s.printing_last_child = (node->right_child_ == NULL);
            count_vertexs(node->left_child_);
        }
        if (node->right_child_ != NULL) {
            s.printing_last_child = 1;
            count_vertexs(node->right_child_);
        }

        if (parent_state != NULL) {
            parent_state->child_state = NULL;
        }
        else {

            _root_state = NULL;

        }

    };

}

void go(struct Vertex* node) {

    if ((node->left_child_ == NULL && node->right_child_ != NULL) || (node->left_child_ != NULL && node->right_child_ == NULL))counter++;
    if (node->left_child_ != NULL) go(node->left_child_);
    if (node->right_child_ != NULL) go(node->right_child_);

}
int main() {

	struct Vertex* tree = new_vertex(0);

    int input = 1;
    int input_data = 0;

    while (input) {

        printf("Input new data: ");
        scanf_s("%d", &input_data);
       
        if (!input_data)input = 0;
        else
            add_data(tree, input_data);

    }

   print_tree(tree);

    go(tree);
    printf("Number of vertexs: %d.", counter);
	return 0;
}