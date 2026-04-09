void Display_Loop() {
    switch(CurrentScreen){
        case 0x1000:
            Display_Main();
            break;
        default:
            break;
    }
}