
# include "PmergeMe.hpp"

PmergeMe::PmergeMe(): _last(-1){}
PmergeMe::~PmergeMe(){}

void PmergeMe::printVec() const { printContainer(_vec); }
void PmergeMe::printDeq() const { printContainer(_deq); }

size_t PmergeMe::getVecSize() const { return _vec.size(); }
size_t PmergeMe::getDeqSize() const { return _deq.size(); }

//Vector______________________________________________________________________
void PmergeMe::loadData_Vec(char **argv)
{
	if (argv == NULL || argv[0] == NULL)
		throw std::bad_alloc();

	std::string temp;
	for (int i = 1; argv[i] != NULL; ++i) 
	{
		temp = argv[i];
		if (temp.find_first_not_of("0123456789") != std::string::npos)
			throw std::domain_error("invalid argument");
	    _vec.push_back(strtoul(argv[i], NULL, DECIMAL_BASE));
	}
}

void PmergeMe::sort_Vec(char **argv)
{
	loadData_Vec(argv);
	if (_vec.empty())
	{
		std::cout << "Container is empty, nothing to sort" << std::endl;
		return ;
	}
	FJohnsonSortVec();
}

//JOHNSON
int PmergeMe::binarySearchVec(std::vector<size_t>& arr, size_t num, int left, int right)
{
    if (right <= left)
        return (num > arr[left]) ? (left + 1) : left;
 
    int mid = (left + right) / 2;
 
    if (num == arr[mid]) 
        return mid + 1; //doesnt matter if + or -
 
    if (num > arr[mid])
		return binarySearchVec(arr, num, mid + 1, right);
    return binarySearchVec(arr, num, left, mid - 1);
}


void PmergeMe::FJohnsonSortVec()
{
	pair_vector pairs;
	int odd;
	int size = _vec.size();

	if (size <= 1)
		return ;
	if  (size % 2 == 0)
		odd = 0;
	else
		odd = 1;
	
	generate_pairsVec(pairs);
	sort_pairsVec(pairs);
	_vec.clear();
	
	//creating main-chain
	for (size_t i = 0; i < pairs.size(); i++) 
	    _vec.push_back(pairs[i].second);
	_vec.insert(_vec.begin(), pairs[0].first); //the smaller number of the smallest pair
	
	if (odd)
		pairs.push_back(std::make_pair(_last, _last)); //pushing the lonely B to the pairs
	
	std::vector<int> indexForBs = getB_indicesVec(size / 2 + odd);
	for (size_t i = 0; i < pairs.size() - 1; i++) // -1 kinda confusing cuz i insert b1 at main-chain
	{
		int indx = binarySearchVec(_vec, pairs[indexForBs[i]].first, 0, _vec.size() - 1);
	    _vec.insert(_vec.begin() + indx, pairs[indexForBs[i]].first);
    }
	return ;
}

void PmergeMe::sort_pairsVec(pair_vector& pairs)
{
	if (pairs.size() <= 1) 
        return ; 

	int middle = pairs.size() / 2;
	pair_vector leftArr(pairs.begin(), pairs.begin() + middle);
	pair_vector rightArr(pairs.begin() + middle, pairs.end());

	sort_pairsVec(leftArr);
    sort_pairsVec(rightArr);

	int leftIndx = 0;
	int rightIndx = 0;
	int lSize = leftArr.size();
	int rSize = rightArr.size();

	for (size_t i = 0; i < pairs.size() ; i++)
	{
		if (leftIndx == lSize)
			pairs[i] = rightArr[rightIndx++];
		else if (rightIndx == rSize)
			pairs[i] = leftArr[leftIndx++];
		else if (leftArr[leftIndx].second < rightArr[rightIndx].second)
			pairs[i] = leftArr[leftIndx++];
		else
			pairs[i] = rightArr[rightIndx++];
	}
}

void PmergeMe::generate_pairsVec(pair_vector& pairs) 
{
    if (_vec.size() % 2 != 0) 
	{
        _last = _vec.back();
        _vec.pop_back();
    }
    for (size_t i = 0; i < _vec.size(); i += 2) 
	{
        // If the first element is bigger than the second, swap them
        if (_vec[i] > _vec[i + 1]) //greater is always pair.second
		{
            std::swap(_vec[i], _vec[i + 1]);
        }
        pairs.push_back(std::make_pair(_vec[i], _vec[i + 1]));
    }
}


//here my jacobs is the true jacobsthal number - 1
std::vector<int> PmergeMe::getB_indicesVec(int numberOfBs)
{
    std::vector<int> indexForB;
	int jacobs = 0;
	int last_jacob;
	int n = 0;
	int j = 3;
  
    while (jacobs < numberOfBs)
	{
		last_jacob = jacobs;
		jacobs = getJacobsthalNumber(j) - 1;
		if (jacobs > numberOfBs - 1)
		{
			for (n = numberOfBs - 1; n > last_jacob; n--)
		    	indexForB.push_back(n);
			break;
		}
		indexForB.push_back(jacobs);
        for (n = jacobs - 1; n > last_jacob; n--)
		    indexForB.push_back(n);
		j++;
	}
	// std::cout << "Vector elements: ";
    // for (std::vector<int>::iterator it = indexForB.begin(); it != indexForB.end(); ++it) {
        // std::cout << *it + 1 << " ";
    // }
    // std::cout << std::endl;
    return indexForB;
}

//HELPER___________________________________________________________
size_t PmergeMe::getJacobsthalNumber(size_t n) const
{
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return getJacobsthalNumber(n - 1) + 2 * getJacobsthalNumber(n - 2);
}

void PmergeMe::checkSort()
{
	for (size_t i = 1; i < _vec.size(); ++i) 
	{
        if (_vec[i - 1] > _vec[i]) 
		{
			std::cout << "Check: Vector is NOT sorted ❌" << std::endl;
        }
    }
	std::cout << "Check: Vector is sorted ✅" << std::endl;
	return ;
}


/* void PmergeMe::insertionSort(std::vector<size_t>& arr, int len)
{
    int i, loc, leftFromI, selected;
 
    for (i = 1; i < len; ++i)
    {
        leftFromI = i - 1;
        selected = arr[i];
 
        // find location where selected should be inserted
        loc = binarySearchVecVec(arr, selected, 0, leftFromI);
 
        // Move all elements after location to create space
        while (leftFromI >= loc)
        {
            arr[leftFromI + 1] = arr[leftFromI];
            leftFromI--;
        }
        arr[leftFromI + 1] = selected;
    }
} */
