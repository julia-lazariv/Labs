// Lab_12_10.cpp
// < Юлія Лазарів >
// Лабораторна робота № 12_10
// Дерева
// Варіант 3

#include <string>
#include <iostream>
#include <sstream>
#include <cassert>
#include <fstream>
 
enum Type{PLUS,MUL,VAL};
 
struct Node;
 
struct Node
{ 
   Type type;
   Node* left, *right;
   int data;
};
 
void recurs( std::string str, Node* node )
{
  
   int i, c; 
  
   std::cout << str << std::endl; 
   for( unsigned t = PLUS; t < VAL; ++t )
      for( i=0, c=0;i<str.size();++i )
      {
          if( '(' == str[i] )
            ++c;
          else if( ')' == str[i] )
            --c;
          else if( (t == PLUS ? '+' : '*') == str[i] && !c )
          {
            node->left = new Node;
            node->right = new Node; 
            node->type = static_cast<Type>( t ); 
            std::cout << ( node->type == PLUS ? "+" : "*" ) << std::endl; 
            recurs( str.substr( 0, i ), node->left );
            recurs( str.substr( i+1, str.size() - i ), node->right ); 
            return; 
          }        
      } 
     
   if( str[0] == '(' && str[str.size()-1] == ')' )
   { 
      recurs( str.substr( 1, str.size() - 2 ), node ); 
      return; 
   } 
     
   node->type = VAL;
   std::stringstream istr( std::stringstream::in | std::stringstream::out );
   istr << str;
   istr >> node->data; 
}
 
int recurs( Node* node )
{
  std::cout << "<<" << std::endl;
  int val = 0; 
  switch( node->type )
  {
    case PLUS:  
      val = recurs( node->left ) + recurs( node->right );
      break; 
    case MUL:
      val = recurs( node->left ) * recurs( node->right );  
      break; 
    case VAL:
      val = node->data;
      std::cout << "(" << val << ")" << std::endl;
      break; 
    default:
      assert( 0 );  
      return -1;  
  }   
  delete node; 
  return val; 
} 

std::string StringFromfile(std::string filename)
{
	std::string str("(((10+1)*(5+6*(3+1))+4*(3+1)))");
	std::ofstream fout(filename, std::ios::binary);
	size_t n = str.size();
	fout.write((const char*)&n, sizeof(n));
	fout.write(str.c_str(), n);
	fout.close();

	std::ifstream fin(filename, std::ios_base::binary);
	std::string s = "";

	if (fin)
	{
		int n = 0;
		fin.read((char*)&n, sizeof(n));
		s.resize(n);
		fin.read(&s[0], n);
		fin.close();
	}
	return s;
}
 
int main()
{
   std::string filename;
   std::cout << "Enter filename: "; std::cin >> filename;
   std::string str = StringFromfile(filename);

   Node* node = new Node;;
   recurs( str, node );
   std::cout << "result = " << recurs( node );  
}