const { SerialPort } = require('serialport');
const { ReadlineParser } = require('@serialport/parser-readline');
const player = require('play-sound')((opts = {}));

const port = new SerialPort(
    {
        path: 'COM3',
        baudRate: 9600,
    },
    // callback for catching open related errors
    function (err) {
        if (err) {
            return console.log('Error: ', err.message);
        }
    }
);

const parser = port.pipe(new ReadlineParser({ delimiter: '\r\n' }));

const events = ['SUNRISE', 'LIGHT RAIN', 'THUNDER STORM', 'NIGHTFALL'];
const sounds = [
    'birds_chirping',
    'light_rain',
    'thunder_storm',
    'night_ambience',
];

// listens for when there is data available to be read from the stream
parser.on('data', (data) => {
    console.log(data);

    const i = events.indexOf(data);
    if (i >= 0) play(i);
});

function play(i) {
    player.play(`./mp3/${sounds[i]}.mp3`, { player: 'mplayer.exe' }, (err) => {
        if (err) throw err;
    });
}
