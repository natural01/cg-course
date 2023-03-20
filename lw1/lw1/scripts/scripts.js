import { getSVGEric } from './SVG/SouthPark.js'; 
import { getSVGHome } from './SVG/home.js'
import { getSVGBus } from './SVG/bus.js'
import { getSVGComputer } from './SVG/computer.js'
import { getSVGFlower } from './SVG/flower.js'
import { getSVGCar } from './SVG/car.js'
import { getSVGRocet } from './SVG/rocet.js'
import { getSVGMore } from './SVG/more.js'
import { figures } from './figures/figures.js'

document.getElementById(figures.HOME).addEventListener("click", addElem(figures.HOME));
document.getElementById(figures.BUS).addEventListener("click", addElem(figures.BUS));
document.getElementById(figures.ERIC).addEventListener("click", addElem(figures.ERIC));
document.getElementById(figures.FLOWER).addEventListener("click", addElem(figures.FLOWER));
document.getElementById(figures.CAR).addEventListener("click", addElem(figures.CAR));
document.getElementById(figures.ROCET).addEventListener("click", addElem(figures.ROCET));
document.getElementById(figures.COMPUTER).addEventListener("click", addElem(figures.COMPUTER));
document.getElementById(figures.MORE).addEventListener("click", addElem(figures.MORE));

function addElem(name) {
    return function() {
        const erics = document.querySelectorAll('.' + name);
        if (erics.length > 0) {
            console.log("count of `" + name + "` can't be more than one!");
        } else {
            console.log('`' + name + '` has been add');
            switch (name) {
                case 'home':
                    document.getElementById('window').appendChild(getSVGHome());
                    break;
                case 'eric':
                    document.getElementById('window').appendChild(getSVGEric());
                    break;
                case 'bus':
                    document.getElementById('window').appendChild(getSVGBus());
                    break;
                case 'computer':
                    document.getElementById('window').appendChild(getSVGComputer());
                    break;
                case 'flower':
                    document.getElementById('window').appendChild(getSVGFlower());
                    break;
                case 'car':
                    document.getElementById('window').appendChild(getSVGCar());
                    break;
                case 'rocet':
                    document.getElementById('window').appendChild(getSVGRocet());
                    break;
                case 'more':
                    document.getElementById('window').appendChild(getSVGMore());
                    break;
            } 
        }
    }
}