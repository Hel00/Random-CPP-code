#include <algorithm>
#include <array>
#include <vector>
#include <iostream>

template < std::size_t N >
void bucketSort( std::array<float, N>& bucketArray )
{
  std::vector<float> bucket[ N ];

  // Put array elements in different buckets
  for ( std::size_t index = 0; index < N; index++ )
  {
    int bucketIndex = static_cast<int>( N * bucketArray[ index ] );
    bucket[ bucketIndex ].push_back( bucketArray[ index ] );
  }

  // Sort individual buckets
  for ( std::size_t index = 0; index < N; index++ )
  {
    std::sort( bucket[ index ].begin(), bucket[ index ].end() );
  }

  // Concatenate all buckets into arr[]
  std::size_t bucketIndex = 0;
  for ( std::size_t index = 0; index < N; index++ )
  {
    for ( std::size_t bucketSubindex = 0; bucketSubindex < bucket[ index ].size(); bucketSubindex++ )
    {
      bucketArray[ bucketIndex++ ] = bucket[ index ][ bucketSubindex ];
    }
  }
}

int main()
{
  std::array<float, 5> input = { 0.3f, 0.1f, 0.5f, 0.2f, 0.4f };

  bucketSort( input );

  for ( const auto& element : input )
  {
    std::cout << element << ' ';
  }

  std::cout << std::endl;

  return 0;
}
