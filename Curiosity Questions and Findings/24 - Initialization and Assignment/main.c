int main()
{
	// invalid
	int a = b = 0; // since b here was undeclared and has no type

	// valid
	int a,b;
	a = b = 0;

	return 0;
}