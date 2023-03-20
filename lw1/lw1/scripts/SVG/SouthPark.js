export const getSVGEric = () => {
    const div = document.createElement('div');
  
    div.className = 'eric';
    div.innerHTML = `
        <svg xmlns="http://www.w3.org/2000/svg" width="450px" height="400" viewPort="0 0 120 120" version="1.1">
            <polygon points="83,299 98,343 372,342 389,297" fill="#7b4129" stroke="none" />
            <polygon points="104,166 365,168 382,174 395,186 405,202 410,205 407,261 405,285 396,299 381,307 341,312 313,312 297,317 283,321 259,327 239,328 211,328 175,330 121,323 101,314 78,297 72,269 60,213 87,179 105,167" fill="#ff2143" stroke="none" />
            <polygon points="91,346 90,341 151,333 216,334 233,340 245,340 273,334 341,334 360,338 380,343 381,346" fill="#2d2f3b" stroke="none" />
            <ellipse fill="#fff0c5" cx="234" cy="132" rx="140" ry="110"/>
            <ellipse fill="#00b9cd" cx="235" cy="110" rx="140" ry="100"/>
            <polygon points="169,224 109,171 95,120 139,100 237,73 296,76 377,103 373,151 322,210" fill="#fff0c5" stroke="none" />
            <polygon points="189,16 193,21 202,21 213,13 215,22 220,22 229,18 236,22 246,22 250,18 265,18 269,13 264,5 257,4 238,-4 235,0 215,-1 210,3 204,6 194,9 " fill="#f9e129" stroke="none" />
            <circle fill="#fdfdfd" cx="200" cy="130" r="30"/>
            <circle fill="#fdfdfd" cx="207" cy="122" r="32"/>
            <circle fill="#fdfdfd" cx="215" cy="115" r="30"/>
            <circle fill="#fdfdfd" cx="282" cy="130" r="30"/>
            <circle fill="#fdfdfd" cx="279" cy="122" r="32"/>
            <circle fill="#fdfdfd" cx="275" cy="115" r="30"/>
            <circle fill="#2c2b30" cx="219" cy="121" r="4"/>
            <circle fill="#2c2b30" cx="263" cy="121" r="4"/>
            <!-- polygon points="230,208 215,193 221,189 259,190 262,193 253,212 244,213 230,209" fill="#2c2b30" stroke="none" /-->
            <rect x="224" y="192" fill="#fdfdfd" width="10" height="5"/>
            <rect x="236" y="192" fill="#fdfdfd" width="10" height="5"/>
            <rect x="248" y="192" fill="#fdfdfd" width="10" height="5"/>
            <polyline points="221,214 234,217 255,218 270,214" fill="none" stroke="#897955" />
            <polyline points="128,187 166,212 181,220 236,229 261,227 289,219 334,195 351,180" fill="none" stroke="#897955" />
            <path d="M 95 120 q 150 -80 280 -18" stroke="#f9e129" stroke-width="8" fill="none" />
            <polygon points="105,264 69,266 56,259 48,248 46,238 46,229 51,220 59,215 69,214 78,217 108,235 111,240 117,246 118,252 117,259" fill="#fee01c" stroke="none" />
            <polygon points="422,252 407,261 400,262 382,252 365,253 362,249 361,240 369,232 370,228 383,208 390,208 408,204 418,207 426,234 426,246" fill="#fee01c" stroke="none" />
            <polyline points="251,327 253,292 255,278 255,240" fill="none" stroke="#48120f" />
            <ellipse fill="#48120f" cx="244" cy="247" rx="2" ry="4"/>
            <ellipse fill="#48120f" cx="248" cy="280" rx="2" ry="4"/>
            <ellipse fill="#48120f" cx="244" cy="312" rx="2" ry="4"/>
        </svg>
    `;
  
    return div;
}