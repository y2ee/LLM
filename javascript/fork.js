// fork함수랑 vfork 함수를 사용하지 않고 자식 프로세스를 생성하는 코드를 js언어로 짜줘

const { spawn } = require('child_process');
const child = spawn('node', ['javascript/db.js']);

child.stdout.on('data', (data) => {
    console.log(`stdout: ${data}`);
    }
);

child.stderr.on('data', (data) => {
    console.error(`stderr: ${data}`);
    }
);

child.on('close', (code) => {
    console.log(`child process exited with code ${code}`);
    }
);











