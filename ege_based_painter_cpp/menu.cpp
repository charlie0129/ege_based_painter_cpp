#include "menu.h"

void Menu(bool readResult)
{
    const short int TOTAL_LN = 8;

    cleardevice();
    InitUI(0);
    printf("请在菜单界面用鼠标点击操作\n");
    DrawMenuOutline(1, TOTAL_LN, 1);
    setcolor(0x000000);
    PrintMenu(0);
    mouse_msg msg;

    for (; ; delay_fps(REFRESH_RATE))
    {
        msg = getmouse();

        switch (msg.msg)
        {
            case mouse_msg_down:
                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 1: // 退出
                        if (g_isFileEdited)
                        {
                            int selection = MessageBox(NULL,
                                                       TEXT("当前有更改未保存，是否确定要退出？"),
                                                       TEXT("提示"),
                                                       MB_OKCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                            if (selection == IDOK)
                            {
                                return;
                            }
                            else if (selection == IDCANCEL)
                            {
                                break;
                            }
                        }

                        return;
                        break;

                    case 2: // 另存为
                        WriteToFile();
                        goto move;
                        break;

                    case 3: // 清除所有图形
                        if (true)
                        {
                            int selection1 = MessageBox(NULL,
                                                        TEXT("是否确定清除所有图形？此操作无法撤回。"),
                                                        TEXT("提示"),
                                                        MB_OKCANCEL | MB_SYSTEMMODAL | MB_ICONEXCLAMATION);

                            if (selection1 == IDOK)
                            {
                                ClearData();
                                cleardevice();
                                InitUI(0);
                                delay_fps(REFRESH_RATE);
                                MessageBox(NULL,
                                           TEXT("已清除所有图形"),
                                           TEXT("提示"),
                                           MB_OK | MB_SYSTEMMODAL | MB_ICONINFORMATION);

                                goto move;
                            }
                            else if (selection1 == IDCANCEL)
                            {
                                break;
                            }
                        }

                        break;

                    case 4: // 画线
                        cleardevice();
                        InitUI(0);
                        mouse_DrawLine();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 5: // 画圆
                        cleardevice();
                        InitUI(0);
                        mouse_DrawCircle();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 6: // 画矩形
                        cleardevice();
                        InitUI(0);
                        mouse_DrawRectangle();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 7: // 画多边形
                        cleardevice();
                        InitUI(0);
                        mouse_DrawPoly();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    case 8: // 运算符重载测试
                        cleardevice();
                        operator_test();
                        cleardevice();
                        InitUI(0);
                        goto move;
                        break;

                    default:
                        break;
                }

                break; // not needed

            case mouse_msg_move:
move:
                setcolor(0x50AA50);
                xyprintf(678, 582, "当前坐标: (%03d, %03d)", msg.x, msg.y);
                DrawAllPrevShapes(false);
                DrawMenuOutline(1, TOTAL_LN, 1);

                switch (GetMouseCurrentLnAndCol(1, TOTAL_LN, 1, 1).ln)
                {
                    case 0:
                        DrawMenuOutline(1, TOTAL_LN, 1);
                        setcolor(0x000000);
                        PrintMenu(0);
                        break;

                    case 1:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(1);
                        break;

                    case 2:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(2);
                        break;

                    case 3:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(3);
                        break;

                    case 4:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(4);
                        break;

                    case 5:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(5);
                        break;

                    case 6:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(6);
                        break;

                    case 7:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(7);
                        break;

                    case 8:
                        setcolor(0x000000);
                        PrintMenu(0);
                        setcolor(0x5050AA);
                        PrintMenu(8);
                        break;

                    default:
                        break;
                }

                break;

            default:
                break;
        }
    }
}


void PrintMenu(short int lnToPrint)
{
    switch (lnToPrint)
    {
        case 0:
            setfont(40, 0, "Segoe UI");
            xyprintf(graphicsEnvironment.GetMenuWidth() + 170, 250, "欢迎来到 CC 画板");
            setfont(graphicsEnvironment.GetFontSize(), 0, graphicsEnvironment.GetFont());
            /*xyprintf(graphicsEnvironment.GetMenuWidth() + 118, 300,
                     "注：如需检查作业完成情况请看带有“(作业)”的选项");*/
            xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "退出");
            xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "另存为");
            xyprintf(8, 8 + 2 * graphicsEnvironment.GetMenuHeight(), "清除所有图形");
            xyprintf(8, 8 + 3 * graphicsEnvironment.GetMenuHeight(), "用鼠标画线");
            xyprintf(8, 8 + 4 * graphicsEnvironment.GetMenuHeight(), "用鼠标画圆");
            xyprintf(8, 8 + 5 * graphicsEnvironment.GetMenuHeight(), "用鼠标画矩形");
            xyprintf(8, 8 + 6 * graphicsEnvironment.GetMenuHeight(), "用鼠标画多边形");
            xyprintf(8, 8 + 7 * graphicsEnvironment.GetMenuHeight(), "运算符重载测试");
            break;

        case 1:
            xyprintf(8, 8 + 0 * graphicsEnvironment.GetMenuHeight(), "退出");
            break;

        case 2:
            xyprintf(8, 8 + 1 * graphicsEnvironment.GetMenuHeight(), "另存为");
            break;

        case 3:
            xyprintf(8, 8 + 2 * graphicsEnvironment.GetMenuHeight(), "清除所有图形");
            break;

        case 4:
            xyprintf(8, 8 + 3 * graphicsEnvironment.GetMenuHeight(), "用鼠标画线");
            break;

        case 5:
            xyprintf(8, 8 + 4 * graphicsEnvironment.GetMenuHeight(), "用鼠标画圆");
            break;

        case 6:
            xyprintf(8, 8 + 5 * graphicsEnvironment.GetMenuHeight(), "用鼠标画矩形");
            break;

        case 7:
            xyprintf(8, 8 + 6 * graphicsEnvironment.GetMenuHeight(), "用鼠标画多边形");
            break;

        case 8:
            xyprintf(8, 8 + 7 * graphicsEnvironment.GetMenuHeight(), "运算符重载测试");
            break;

        default:
            break;
    }
}

