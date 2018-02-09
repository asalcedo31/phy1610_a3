 // deallocation of 2D int arrays 
void deallocate_int_matrix(int **a) {
	//delete the array of pointers
    delete[] a[0];
    //delete the first pointer
    delete[] a;
}

//deallocation of 2D float arrays 
void deallocate_float_matrix(float **a) {
	//delete the array of pointers
    delete[] a[0];
    //delete the first pointer
    delete[] a;
}

