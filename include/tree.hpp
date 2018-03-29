#include <iostream>
#include <sstream>
#include <string>

class tree_t
{
private:
    struct node_t
    {
        node_t* left;
        node_t* right;
        int value;
    };

private:
    node_t* root_;

public:
    tree_t()
    {
        root_ = nullptr;
    }

    void insert(int value)
    {
        if (root_ == nullptr)
        {
            root_ = new node_t;
            root_->value = value;
            root_->left = nullptr;
            root_->right = nullptr;
        }
        else
        {
            node_t* run_ = root_;
            while (run_ != nullptr)
            {
                if (value < run_->value)
                {
                    if (run_->left == nullptr)
                    {
                        run_->left = new node_t;
                        run_ = run_->left;
                        run_->value = value;
                        run_->left = nullptr;
                        run_->right = nullptr;
                    }
                    else
                    {
                        run_ = run_->left;
                    }
                }
                else if (value >= run_->value)
                {
                    if (run_->right == nullptr)
                    {
                        run_->right = new node_t;
                        run_ = run_->right;
                        run_->value = value;
                        run_->left = nullptr;
                        run_->right = nullptr;
                    }
                    else
                    {
                        run_ = run_->right;
                    }
                }
            }
        }
    }

    bool find(int value) const
    {
        if (root_ == nullptr)
        {
            return false;
        }
        else
        {
            node_t* run_ = root_;
            while (run_ != nullptr)
            {
                if (run_->value == value)
                {
                    return true;
                }
                else if (run_->value < value)
                {
                    run_ = run_->right;
                }
                else if (run_->value > value)
                {
                    run_ = run_->left;
                }
            }
            return false;
        }
    }

    node_t* root()
    {
        return root_;
    }
    
    ~tree_t () {
	if( root_ != nullptr) {
		delete(root_);
	}
    }
    
    void delete(node_t * run_){
        if(run_!=nullptr){
            if(run_->left!=nullptr){
                delete(run_->left);
            }
            if(run_->right!=nullptr){
                delete(run_->right);
            }
            delete run_;
        }
    }

    void print(std::ostream & stream ,  node_t * run_ , size_t u) const
	{
		if (run_->right!=nullptr) {
			u++;
			print(stream ,run_->right, u);
			u--;
		}
		for (size_t k = 0; k < u; k++) {
			stream << "--";
		}
			stream << run_->value << std::endl;
		if (run_->left!=nullptr) {
			u++;
			print(stream ,run_->left, u);
			u--;
		}
	}
};

bool read(tree_t& tree)
{
    char op;
    int value;
    std::string stroka;
    getline(std::cin, stroka);
    std::istringstream stream(stroka);
    if (stream >> op && (op == '=' || op == '+' || op == '?' || op == 'q'))
    {
        if ((op == '+' || op == '?') && stream >> value)
        {
            if (op == '+')
            {
                tree.insert(value);
            }
            else if (op == '?')
            {
                std::cout << tree.find(value) << std::endl;
            }
        }
        else if (op == '=')
        {
            tree.print(stream, tree.root(), 0);
            std::cout << stream.str();
        }
        else if (op == 'q')
        {
            return false;
        }
    }
}
