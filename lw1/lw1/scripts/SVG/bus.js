export const getSVGBus = () => {
    const div = document.createElement('div');
  
    div.className = 'bus';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="180px" height="160" viewPort="0 0 120 120" version="1.1">
            <line x1="0" y1="5" x2="137" y2="5" stroke="black" />
            <line x1="3" y1="8" x2="140" y2="8" stroke="black" />
            <rect x="20" y="40" width="120" height="50" rx="10" ry="5" fill="silver" />
            <rect x="70" y="35" width="20" height="5" fill="silver" />
            <circle cx="50" cy="90" r="10" />
            <circle cx="110" cy="90" r="10" />
            <rect x="42" y="50" width="15" height="20" fill="white" />
            <rect x="62" y="50" width="15" height="20" fill="white" />
            <rect x="82" y="50" width="15" height="20" fill="white" />
            <rect x="102" y="50" width="15" height="20" fill="white" />
            <rect x="122" y="50" width="15" height="20" fill="white" />
            <line x1="75" y1="35" x2="30" y2="5" stroke="black" />
            <line x1="85" y1="35" x2="43" y2="8" stroke="black" />
        </svg>
    `;
  
    return div;
}