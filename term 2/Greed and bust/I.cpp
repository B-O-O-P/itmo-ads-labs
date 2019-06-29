#include <iostream>
#include <vector>

using namespace std;

int n = 4;
vector<vector<int>> a;

vector<vector<int>> mul(vector<vector<int>>& a, vector<vector<int>>& b) {
    vector<vector<int>> c((unsigned) n);
    for (int i = 0; i < n; i++) {
        c[i].resize((unsigned) n);
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            c[i][j] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][j] += (a[i][k] * b[k][j]);
            }
            c[i][j] = c[i][j] % 2;
        }
    }

    return c;
}

int main() {
    freopen("sqroot.in", "r", stdin);
    freopen("sqroot.out", "w", stdout);

    a.resize((unsigned) n);
    for (int i = 0; i < n; i++) {
        a[i].resize((unsigned) n);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vector <vector<int>> b;
    b.resize((unsigned) n);
    for (int i = 0; i < n; i++)
        b[i].resize((unsigned) n);

    for (int b00 = 0; b00 < 2; b00++) {
        b[0][0] = b00;
        for (int b01 = 0; b01 < 2; b01++) {
            b[0][1] = b01;
            for (int b02 = 0; b02 < 2; b02++) {
                b[0][2] = b02;
                for (int b03 = 0; b03 < 2; b03++) {
                    b[0][3] = b03;
                    for (int b10 = 0; b10 < 2; b10++) {
                        b[1][0] = b10;
                        for (int b11 = 0; b11 < 2; b11++) {
                            b[1][1] = b11;
                            for (int b12 = 0; b12 < 2; b12++) {
                                b[1][2] = b12;
                                for (int b13 = 0; b13 < 2; b13++) {
                                    b[1][3] = b13;
                                    for (int b20 = 0; b20 < 2; b20++) {
                                        b[2][0] = b20;
                                        for (int b21 = 0; b21 < 2; b21++) {
                                            b[2][1] = b21;
                                            for (int b22 = 0; b22 < 2; b22++) {
                                                b[2][2] = b22;
                                                for (int b23 = 0; b23 < 2; b23++) {
                                                    b[2][3] = b23;
                                                    for (int b30 = 0; b30 < 2; b30++) {
                                                        b[3][0] = b30;
                                                        for (int b31 = 0; b31 < 2; b31++) {
                                                            b[3][1] = b31;
                                                            for (int b32 = 0; b32 < 2; b32++) {
                                                                b[3][2] = b32;
                                                                for (int b33 = 0; b33 < 2; b33++) {
                                                                    b[3][3] = b33;
                                                                    vector <vector<int>> sqrtb = mul(b, b);
                                                                    bool equals = true;
                                                                    for (int i = 0; i < n; i++) {
                                                                        for (int j = 0; j < n; j++) {
                                                                            if (a[i][j] != sqrtb[i][j]) {
                                                                                equals = false;
                                                                                break;
                                                                            }
                                                                        }
                                                                        if (!equals)break;
                                                                    }
                                                                    if (equals) {
                                                                        for (int i = 0; i < n; i++) {
                                                                            for (int j = 0; j < n; j++) {
                                                                                printf("%d ", b[i][j]);
                                                                            }
                                                                            printf("\n");
                                                                        }
                                                                        return 0;
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    printf("NO SOLUTION");
    return 0;
}