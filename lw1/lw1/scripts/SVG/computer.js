export const getSVGComputer = () => {
    const div = document.createElement('div');
  
    div.className = 'computer';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="230px" height="110" viewPort="0 0 120 120" version="1.1">
            <rect x="0" y="0" width="150" height="80" />
            <rect x="10" y="10" width="130" height="60" fill="white" />
            <rect x="70" y="80" width="10" height="30" />
            <polyline points="50 110, 70 100, 80 100, 100 110" />
            <circle cx="135" cy="75" r="2" fill="silver" />
            <line x1="120" y1="72" x2="120" y2="78" stroke="white" />
            <rect x="180" y="0" width="50" height="110" />
            <rect x="185" y="10" width="40" height="20" fill="silver" />
            <rect x="186" y="11" width="38" height="18" />
            <line x1="188" y1="18" x2="223" y2="18" stroke="silver" />
            <circle cx="223" cy="45" r="5" fill="red" />
            <circle cx="213" cy="45" r="3" fill="green" />
            <circle cx="203" cy="45" r="3" fill="silver" />
            <line x1="180" y1="80" x2="150" y2="110" stroke="black" />
            <line x1="150" y1="110" x2="110" y2="110" stroke="black" />
            <line x1="110" y1="110" x2="70" y2="80" stroke="black" />
        </svg>
    `;
  
    return div;
}