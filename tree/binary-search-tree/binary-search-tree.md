# 이진 검색 트리
노드의 데이터에 어떠한 제한도 가하지 않는 경우, 어떤 항목을 검색하려면, 왼쪽 부속 트리와 오른쪽 부속 트리를 모두 검사해야 하기 때문에 검색 연산의 최악의 경우 복잡도는 O(n)인 상태였다.
이진 검색 트리에서는 어떤 노드가 가질 수 있는 데이터의 종류에 대하여 제한을 둘 것이므로, 검색 연산의 최악의 경우 복잡도가 O(logn)이 된다.