export const getSVGHome = () => {

    const div = document.createElement('div');
  
    div.className = 'home';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="180px" height="160" viewPort="0 0 120 120" version="1.1">
            <rect x="0" y="100" width="180" height="60" fill="green" />
            <rect x="30" y="0" width="10" height="40" fill="red" />
            <rect x="110" y="90" width="70" height="5" fill="#48120f" />
            <rect x="110" y="110" width="70" height="5" fill="#48120f" />
            <rect x="10" y="30" width="100" height="100" fill="#48120f" />
            <polyline points="8,32 112,32 62,0 8,32" fill="orange" stroke="#48120f" />
            <rect x="80" y="90" width="20" height="40" fill="orange" />
            <rect x="30" y="70" width="30" height="30" fill="blue" />
            <rect x="120" y="80" width="5" height="50" fill="#48120f" />
            <rect x="140" y="80" width="5" height="50" fill="#48120f" />
            <rect x="160" y="80" width="5" height="50" fill="#48120f" />
        </svg>
    `;
  
    return div;
}