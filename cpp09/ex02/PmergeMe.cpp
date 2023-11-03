
# include "PmergeMe.hpp"




PmergeMe::PmergeMe(){}
PmergeMe::~PmergeMe(){}



void PmergeMe::printVec() const { printContainer(_vec); }
void PmergeMe::printDeq() const { printContainer(_deq); }

size_t PmergeMe::getVecSize() const { return _vec.size(); }
size_t PmergeMe::getDeqSize() const { return _deq.size(); }




//Vector______________________________________________________________________
void PmergeMe::loadData_Vec(char **argv)
{
	if (argv == nullptr || argv[0] == nullptr)
		throw std::bad_alloc();

	std::string temp;
	for (int i = 1; argv[i] != nullptr; ++i) 
	{
		temp = argv[i];
		if (temp.find_first_not_of("0123456789") != std::string::npos)
			throw std::domain_error("invalid argument");
	    _vec.push_back(strtoul(argv[i], NULL, DECIMAL_BASE));
	}
}

void PmergeMe::insertion_Vec(int start, int end)
{
	int j;
	size_t toBeInserted;
	for (int i = start; i < end; i++)
	{
		j = i + 1;
		toBeInserted = _vec[j];
		while (j > start && _vec[j - 1] > toBeInserted)
		{
			_vec[j] = _vec[j - 1];
			j--;
		}
		_vec[j] = toBeInserted;
	}
}

void PmergeMe::merge_Vec(int start, int pivot, int end)
{
	int n1 = pivot - start + 1;
	int n2 = end - pivot;

	std::vector<size_t>leftArr(_vec.begin() + start, _vec.begin() + pivot + 1);
	std::vector<size_t>rightArr(_vec.begin() + pivot + 1, _vec.begin() + end + 1);

	int leftIndx = 0;
	int rightIndx = 0;

	for (int i = start; i <= end ; i++)
	{
		if (leftIndx == n1)
			_vec[i] = rightArr[rightIndx++];
		else if (rightIndx == n2)
			_vec[i] = leftArr[leftIndx++];
		else if (leftArr[leftIndx] < rightArr[rightIndx])
			_vec[i] = leftArr[leftIndx++];
		else
			_vec[i] = rightArr[rightIndx++];
	}
}

void PmergeMe::mergeInsertSort_Vec(int start, int end)
{
	if (start > end || start < 0 || end < 0)
	{
		std::cout << "Error: start cant be bigger than end of container and both must be positive" << std::endl;
		return ;
	}
	if (end - start > K)
	{
		int pivot = static_cast<int>((start + end) / 2); 
		//gives me the middle, 0.5 doesnt matter -> below implementation handles it
		mergeInsertSort_Vec(start, pivot);
		mergeInsertSort_Vec(pivot + 1, end);
		merge_Vec(start, pivot, end);
	}
	else 
		insertion_Vec(start, end);
}

void PmergeMe::sort_Vec(char **argv)
{
	loadData_Vec(argv);
	if (_vec.empty())
	{
		std::cout << "Container is empty, nothing to sort" << std::endl;
		return ;
	}
	mergeInsertSort_Vec(0, static_cast<int>(_vec.size() - 1));
}


//Deque______________________________________________________________________
void PmergeMe::loadData_Deq(char **argv)
{
	if (argv == nullptr || argv[0] == nullptr)
		throw std::bad_alloc();

	std::string temp;
	for (int i = 1; argv[i] != nullptr; ++i) 
	{
		temp = argv[i];
		if (temp.find_first_not_of("0123456789") != std::string::npos)
			throw std::domain_error("invalid argument");
	    _deq.push_back(strtoul(argv[i], NULL, DECIMAL_BASE));
	}
}

void PmergeMe::insertion_Deq(int start, int end)
{
	int j;
	size_t toBeInserted;
	for (int i = start; i < end; i++)
	{
		j = i + 1;
		toBeInserted = _deq[j];
		while (j > start && _deq[j - 1] > toBeInserted)
		{
			_deq[j] = _deq[j - 1];
			j--;
		}
		_deq[j] = toBeInserted;
	}
}

void PmergeMe::merge_Deq(int start, int pivot, int end)
{
	int lSize = pivot - start + 1;
	int rSize = end - pivot;
		
	std::deque<size_t>leftArr(_deq.begin() + start, _deq.begin() + pivot + 1);
	std::deque<size_t>rightArr(_deq.begin() + pivot + 1, _deq.begin() + end + 1);

	int leftIndx = 0;
	int rightIndx = 0;

	for (int i = start; i <= end; i++)
	{
		if (leftIndx == lSize)
			_deq[i] = rightArr[rightIndx++];
		else if (rightIndx == rSize)
			_deq[i] = leftArr[leftIndx++];
		else if (leftArr[leftIndx] < rightArr[rightIndx])
			_deq[i] = leftArr[leftIndx++];
		else
			_deq[i] = rightArr[rightIndx++];
	}
}

void PmergeMe::mergeInsertSort_Deq(int start, int end)
{
	if (start > end || start < 0 || end < 0)
	{
		std::cout << "Error: start cant be bigger than end of container and both must be positive" << std::endl;
		return ;
	}
	if (end - start > K)
	{
		int pivot = (start + end) / 2;
		//gives me the middle, 0.5 doesnt matter -> below implementation handles it
		mergeInsertSort_Deq(start, pivot);
		mergeInsertSort_Deq(pivot + 1, end);
		merge_Deq(start, pivot, end);
	}
	else
	{
		insertion_Deq(start, end);
	} 
}


void PmergeMe::sort_Deq(char **argv)
{
	loadData_Deq(argv);
	if (_deq.empty())
	{
		std::cout << "Container is empty, nothing to sort" << std::endl;
		return;
	}
	mergeInsertSort_Deq(0, static_cast<int>(_deq.size() - 1));
}
