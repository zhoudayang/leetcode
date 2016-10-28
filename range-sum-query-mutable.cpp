//segment tree 
class NumArray {
public:
	NumArray(vector<int> &nums):
		size(nums.size()),
		nodes(2*size)
	{
		for(int i=0;i<size;i++)
		{
			nodes[i + size] = nums[i];
		}
		for (int i = size - 1; i >= 0; --i)
			nodes[i] = nodes[2 * i] + nodes[2 * i + 1];
	}

	void update(int pos, int val) {
		pos += size;
		nodes[pos] = val;
		//loop till go to root node 
		while(pos>1)
		{
			int left = pos;
			int right = pos;
			//get right pos of left brother and right brother 
			if (pos % 2 == 0)
				++right;
			else
				--left;
			//update range sum of parent node  
			nodes[pos / 2] = nodes[left] + nodes[right];
			//go to upper level 
			pos >>= 1;
		}
	}

	int sumRange(int l, int r) {
		//get leaf pos 
		l += size;
		r += size;
		int sum = 0;
		while (l <= r)
		{
			//l is the right child of parent node, add nodes[l] to sum and set l to point to the right of parent on the upper level.
			if (l % 2 == 1)
			{
				sum += nodes[l];
				++l;
			}
			//r is the left child of parent node, add nodes[r] to sum and set r to point to left of parent on the upper level 
			if (r % 2 == 0)
			{
				sum += nodes[r];
				--r;
			}
			//both l and r go to higher level
			l >>= 1;
			r >>= 1;
		}
		return sum;
	}
private:
	int size;
	vector<int> nodes;
	
};
//sqrt decomposition 
class NumArray {
public:
    NumArray(vector<int> &nums):nums_(nums),range_(),len_(0) {
        int size = nums_.size();
        if(size){
            len_ = ceil(size/sqrt(size));
            range_.resize(len_);
        }
        for(int i=0;i<size;++i)
            range_[i/len_] += nums_[i];
    }

    void update(int i, int val) {
        int index = i/len_;
        range_[index] = range_[index]-nums_[i] + val;
        nums_[i] = val;
    }

    int sumRange(int i, int j) {
        int start = i/len_;
        int end = j/len_;
        int sum = 0;
        if(start == end){
            for(int k = i;k<=j;++k)
                sum+=nums_[k];
        }else{
            for(int k=i;k<(start+1)*len_;++k)
                sum+=nums_[k];
            for(int k=start+1;k<end;++k)
                sum+=range_[k];
            for(int k=end*len_;k<=j;++k)
                sum+=nums_[k];
        }
        return sum;
    }
private:
    vector<int> nums_;
    vector<int> range_;
    int len_;
};

//refer to https://leetcode.com/articles/range-sum-query-mutable/
