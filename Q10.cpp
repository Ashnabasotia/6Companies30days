
vector <int> kMaxElements(vector<int>& vec)
{
    make_heap(vec.begin(),vec.end());
    vector <int> ans;

    for(int i=0; i<10; i++)
    {
        vec.push_back(vec.front());
        pop_heap();
    }
}