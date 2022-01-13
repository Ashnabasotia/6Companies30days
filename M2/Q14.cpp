class Solution {
  public:
    struct Info{
        int lDepth;
        int rDepth;
        bool contains;
        int time;
        Info(){
            lDepth = rDepth = 0;
            contains = false;
            time = -1;
        }
    };
    Info calcTime(Node* node, Info& info, int target, int& res)
    {
        if(node == NULL)
            return info;
        if(node->data == target)
        {
            info.contains = true;
            info.time = 0;
        }
        Info leftInfo;
        calcTime(node->left, leftInfo, target, res);
        Info rightInfo;
        calcTime(node->right, rightInfo, target,res);
        
        if(node->data != target)
        {
            info.time = (node->left && leftInfo.contains)? (leftInfo.time + 1):-1;
            if(info.time == -1)
            {
                info.time = (node->right && rightInfo.contains)?(rightInfo.time + 1): -1;
            }
            info.contains = ((node->left && leftInfo.contains) || (node->right && rightInfo.contains));
        }
        info.lDepth = !(node->left)?  0 : (1 + max(leftInfo.lDepth,leftInfo.rDepth));
        info.rDepth = !(node->right)? 0 : (1+max(rightInfo.lDepth,rightInfo.rDepth));
        
        if(info.contains){
            
            if(node->data == target)
            {
                res = max(res,max(info.lDepth,info.rDepth));
            }
            if(node->left && leftInfo.contains){
                res = max(res,info.time + info.rDepth);
            }
            if(node->right && rightInfo.contains){
                res = max(res,info.time+info.lDepth);
            }
            
        }
        
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        int res = 0;
        Info info;
        calcTime(root, info, target,res);
        return res;
    }