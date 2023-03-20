export const getSVGCar = () => {
    const div = document.createElement('div');
  
    div.className = 'car';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="180px" height="70" viewPort="0 0 120 120" version="1.1">
            <rect x="10" y="10" width="120" height="50" fill="rgb(232, 224, 71)" />
            <rect x="120" y="20" width="20" height="35" fill="rgb(232, 224, 71)" />
            <polygon points="10 0, 20 0, 25 10, 15 10" fill="rgb(232, 224, 71)"></polygon>
            <circle cx="40" cy="60" r="10" />
            <circle cx="70" cy="60" r="10" />
            <rect x="135" y="5" width="40" height="55" rx="5" ry="5" fill="rgb(232, 224, 71)" />
            <circle cx="145" cy="60" r="10" />
            <polygon points="30 20, 40 20, 50 50, 40 50" fill="yellow"></polygon>
            <polygon points="50 20, 60 20, 70 50, 60 50" fill="yellow"></polygon>
            <polygon points="70 20, 80 20, 90 50, 80 50" fill="yellow"></polygon>
            <rect x="170" y="15" width="5" height="20" fill="silver" />
            <rect x="140" y="15" width="20" height="20" fill="silver" />
            <line x1="140" y1="45" x2="140" y2="15" stroke="black" />
            <line x1="140" y1="15" x2="160" y2="15" stroke="black" />
            <line x1="160" y1="15" x2="160" y2="55" stroke="black" />
            <line x1="160" y1="55" x2="155" y2="55" stroke="black" />
        </svg>
    `;
  
    return div;
}