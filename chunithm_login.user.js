// ==UserScript==
// @name         Chunithm Pass Auto Confirm
// @namespace    pallas1204
// @version      0.1
// @description  パス・ID自動入力
// @author       You
// @match        https://new.chunithm-net.com/
// @icon         https://www.google.com/s2/favicons?sz=64&domain=chunithm-net.com
// @grant        none
// ==/UserScript==

(function() {
    'use strict';

    // Your code here...
    const segaidArea = document.getElementsByName("segaId")[0];
    const passArea = document.getElementsByName("password")[0];
    if(segaidArea && passArea){
        segaidArea.value = "SEGAID";
        passArea.value = "PASSWORD";
    }

})();