// 3-wayHandShake를 javascript언어로 구현해줘

// 3-wayHandShake
// 1. Client가 Server에게 요청을 보낸다.
// 2. Server가 Client에게 응답을 보낸다.
// 3. Client가 Server에게 응답을 보낸다.

// 3-wayHandShake를 구현해보자
// 1. Client가 Server에게 요청을 보낸다.
// 2. Server가 Client에게 응답을 보낸다.
// 3. Client가 Server에게 응답을 보낸다.

// 1. Client가 Server에게 요청을 보낸다.
function requestToServer() {
  console.log('Client: Server에게 요청을 보냅니다.');
  responseToClient();
}

// 2. Server가 Client에게 응답을 보낸다.
function responseToClient() {
  console.log('Server: Client에게 응답을 보냅니다.');
  responseToServer();
}

// 3. Client가 Server에게 응답을 보낸다.
function responseToServer() {
  console.log('Client: Server에게 응답을 보냅니다.');
}

requestToServer();



