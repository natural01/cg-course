export const getSVGRocet = () => {
    const div = document.createElement('div');
  
    div.className = 'rocet';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="110" height="140" viewPort="0 0 120 120" version="1.1">
            <polygon points="30 80, 70 40, 90 60, 50 100" fill="silver"></polygon>
            <polygon points="70 40, 100 30, 90 60" fill="silver"></polygon>
            <polygon points="42 73, 32 70, 42 62, 50 65" fill="silver"></polygon>
            <polygon points="57 92, 57 99, 67 89, 64 85" fill="silver"></polygon>
            <circle cx="68" cy="63" r="8" fill="white" />
            <polygon points="30 80, 3 102, 14 107, 5 135, 30 130, 50 100" fill="yellow"></polygon>
            <polygon points="37 87, 10 100, 16 105, 20 120, 44 94" fill="red"></polygon>
        </svg>
    `;
  
    return div;
}