#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <random>
#include <limits>
#include <cmath>
#include <vector>

using namespace std;

#define LINE_SIZE 256
#define ATT_NUM 4
#define k 16

int main()
{
	FILE* fp;
	char fname[] = "data2.csv";
	char line[LINE_SIZE];
	int dataNum = 0;
	double** data;
	int i, j;
	char* p1;
	char* p2;

	// データ数取得
	if((fp = fopen(fname, "r")) == NULL) {
		printf("ファイル%sが開けません．\n", fname);
		exit(EXIT_FAILURE);
	}
	while(fgets(line, LINE_SIZE, fp))
		dataNum++;
	fclose(fp);

	// メモリ確保
	data = (double**)malloc(sizeof(double*) * dataNum);
	for(i = 0; i < dataNum; i++)
		data[i] = (double*)malloc(sizeof(double) * ATT_NUM);

	// データ読込み
	if((fp = fopen(fname, "r")) == NULL) {
		printf("ファイル%sが開けません．\n", fname);
		exit(EXIT_FAILURE);
	}
	for(i = 0; i < dataNum; i++) {
		fgets(line, LINE_SIZE, fp);
		p2 = strrchr(line, '\n');
		*p2 = ',';
		p1 = line;
		for(j = 0; j < ATT_NUM; j++) {
			p2 = strchr(p1, ',');
			if(!p2) {
				printf("ファイルの形式が正しくありません．\n");
				exit(EXIT_FAILURE);
			}
			*p2 = '\0';
			data[i][j] = atof(p1);
			p1 = p2 + 1;
		}
	}
	fclose(fp);

	// クラスタリング
    int medoid[k];
	int new_medoid[k];
	
	//初期のmedoidを選択
    random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, dataNum-1);
    for(int i=0; i<k; i++) {
        medoid[i]=dis(gen);
    }
	/*
	for(int i=0; i<k; i++) {
		for(int j=0; j<ATT_NUM; j++){
			cout << data[medoid[i]][j] << " ";
		}
		cout << endl;
	}
	*/

	//medoidが変化しなくなるまで繰り返す
	while(true) {
		cout << "#################################" << endl;

		for(int i=0; i<k; i++) {
			new_medoid[i]=medoid[i];
		}
		vector<vector<int>> cluster(k);

		//dataをmedoidのクラスタに割り当てる
		for(int i=0; i<dataNum; i++) {
			double euc_sum;
			double min_eucsum=numeric_limits<double>::max();
			int min_cluster;
			for(int l=0; l<k; l++) {
				euc_sum=0;
				for(int j=0; j<ATT_NUM; j++) {
					euc_sum+=pow(data[i][j]-data[medoid[l]][j], 2);
				}
				if(euc_sum<min_eucsum) {
					min_eucsum=euc_sum;
					min_cluster=l;
				}
			}
			cluster[min_cluster].push_back(i);
		}
		/*
		for(int i=0; i<k; i++) {
			for(int j=0; j<cluster[i].size(); j++) {
				cout << "cluster:" << i << "===" << cluster[i][j] << endl;
			}
		}
		*/

		//最適化ステップ
		for(int i=0; i<k; i++) {
			if(cluster[i].size()==1) {
				new_medoid[i]=cluster[i][0];
			} else {
				double euc_sum;
				double min_eucsum=numeric_limits<double>::max();;
				for(int j=0; j<cluster[i].size(); j++) {
					euc_sum=0;
					for(int m=0; m<cluster[i].size(); m++) {
						for(int l=0; l<ATT_NUM; l++) {
							euc_sum+=pow(data[cluster[i][j]][l]-data[cluster[i][m]][l], 2);
						}
					}
					if(euc_sum<min_eucsum) {
						min_eucsum=euc_sum;
						new_medoid[i]=cluster[i][j];
					}
				}
			}
			
		}
		/*
		for(int i=0; i<k; i++) {
			cout << "new_medoid:" << new_medoid[i] << endl;
			for(int j=0; j<ATT_NUM; j++) {
				cout << data[new_medoid[i]][j] << " ";
			}
			cout << endl;
		}
		*/

		bool flag=true;
		for(int i=0; i<k; i++) {
			if(medoid[i]!=new_medoid[i]) flag=false;
		}
		if(flag) break;

		for(int i=0; i<k; i++) {
			medoid[i]=new_medoid[i];
		}

	}

	//最終的なmedoidの表示
	for(int i=0; i<k; i++) {
		cout << "medoid:" << medoid[i] << endl;
		for(int j=0; j<4; j++) {
			cout << data[medoid[i]][j] << " ";
		}
		cout << endl;
	}
    

	// メモリ解放
	for(i = 0; i < dataNum; i++)
		free(data[i]);
	free(data);
}