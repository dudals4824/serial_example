블록체인 Study Note
=======

## 블록체인 기본 개념
![블록체인기본구조](./image/block_chain.PNG)
- 현재 발생하는 모든 금융 거래 기록들은 Master, VISA 그리고 각 은행 등 금융기관들에 의해
기록, 보관되고 있다. 하지만, 블록체인을 활용하면 금융 거래에 있어서 누구나 금융기관의 역할을 할 수 있다.

- 블록체인 P2P 네트워크의 일원으로서 블록체인 기록을 다운로드 받은 사람들을 *노드(Node)* 라고 부르며, 각자가 금융기관의 역할을 하게 된다. 이 노드의 과반수 이상이 동의했을 때, 기록으로서 영구적으로 장부에 기록된다. *과반수 이상* 이라는 조건이 채굴되는 암호화폐(보상)의 가치를 떨어트리는 일이 될 수 있지만 Bitcoin의 거래 방식을 보면 그렇지 않다고 할 수 있다.

- 블록체인에 있어서는 한명이 하나의 투표권을 가지는 일반적인 선거제도와는 달리 블록이 생성되는 합의 과정에서 *가장 많은 작업(Work)을 한 노드가 어느 기록이 참인지 결정할 수 있는 권한* 을 더 많이 가지게 된다. 이것이 *작업증명(Proof of Work)* 라는 비트코인의 창시자가 고안한 블록 생성 방식이다.

- 기존의 방식과 블록체인이 다른 점, 그리고 비트코인과 같은 가상화폐는 어떻게 발생되는지 보자.

![기존블록체인비교](./image/block_compen.PNG)

- 작업증명을 통해 블록에 거래내역을 정리해주고, *가상화폐* 와 *거래 수수료* 를 받게 되는데 이 과정 *채굴* 이라고 한다.

![채굴](./image/block_compen2.PNG)

## 블록체인의 안전성에 관하여

- 블록체인의 보안에 관해서는 해쉬, 논스 그리고 해쉬파워와 함께 이야기 해야한다.

- 앞서 말한 작업증명의 과정은 컴퓨터 연산을 통해 이루어 진다. 이때 거래된 기록을 암호화하는 과정이 필요하고, 암호화를 위해서는 *SHA256* 이라는 해쉬 함수 프로그램을 사용한다.

- 한 Block 안에서는 *논스(Nonce)* 라는 무작위의 숫자가 SHA256에 대입된다.

![블록체인보안](./image/block_chain_sec.PNG)

- 논스값을 0부터 1씩 반복해서 늘려가며 그 결과로 여러 해시 값이 나오는데, 논스는 블록이 설정해 놓은 특정 해시 값보다 작은 숫자가 나올 때까지 계속 대입된다. 비트코인의 경우, 한 블록은 1MB로 약 10분에 한 개의 블록이 생성되도록 약속되어 있다. 따라서, 작업증명 시스템에서는 블록의 난이도가 설정한 숫자보다 작은 숫자를 더 빠르고 많이 찾을수록 블록체인에 기록하는 과정에서 더 많은 권한이 부여된다. 그렇기 때문에 *연산력(해쉬파워)* 이 좋은 컴퓨터를 가질수록 블록의 기록에 더 많이 관여할 수 있게 된다.


## 비트코인 거래가 이루어지는 과정
