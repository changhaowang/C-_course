
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX_DATE_NUM 1000
#define FACTOR_NUM 20

struct weatherStruct
{
	char date[FACTOR_NUM];
	int highestTem;
	int lowestTem;
	string weatherState;
	string windDir;
	string windLev;
};

int main(void)
{
    ifstream inFile;
    int dayNum=0;
    int i=0;
    
    inFile.open("weather.txt",ios::in);   //以只读形式打开文本
    
    fstream outFile;
    outFile.open("result.txt",ios::out);
    
    if (inFile.fail())
    {
        cout << "打开文件失败！" << endl;
        return 0;
    }
    else
    {
        weatherStruct myWeatherStruct[MAX_DATE_NUM];  //定义结构体组
        
        
        /*读取天气信息到定义的struct*/
        while(!inFile.eof())
        {
            //读取文本
            inFile>>myWeatherStruct[i].date>>myWeatherStruct[i].highestTem>>myWeatherStruct[i].lowestTem>>myWeatherStruct[i].weatherState>>myWeatherStruct[i].windDir>>myWeatherStruct[i].windLev;
            i++;
        }
        inFile.close();
		dayNum = i - 1;
        
        
        int dayHighestTem;      //统计最高每日最高气温
        int dayLowestTem;       //统计最低每日最低气温
        float aveHighestTem;   //平均最高气温
        float aveLowestTem;    //平均最低气温
        string dirWind;         //用于删除风向中“转”、“～”之后的字符串
        string stateWeather;    //用于删除天气中“转”、“～”之后的字符串
        string levWind;         //用于删除风力中“转”、“～”之后的字符串
		
        int lowPos=0;
        int highPos=0;
        int highestSum = 0;
        int lowestSum = 0;
		
		/*统计各种天气对应的天数的变量*/
		int nwQing=0;
		int nwYin=0;
		int nwDuoyun=0;
		int nwXiaoyu=0;
		int nwZhongyu=0;
		int nwZhenyu=0;
		int nwLeizhenyu=0;
		int nwDayu=0;
		int nwYujiaxue=0;
		int nwXiaoxue=0;
		int nwBaoyu=0;
		int nwLeiyu=0;
		
		/*统计各种风对应的天数的变量*/
		int nfDongnan=0;
		int nfDong=0;
		int nfXi=0;
		int nfNan=0;
		int nfBei=0;
		int nfXinan=0;
		int nfXibei=0;
		int nfDongbei=0;
		int nfWeifeng=0;
		
		/*统计各种风力对应的天数的变量*/
		int nlLes3=0;
		int nl3to4=0;
		int nl4to5=0;
		
		
        /*统计各类信息*/
        
        dayHighestTem = myWeatherStruct[0].highestTem;
        dayLowestTem = myWeatherStruct[0].lowestTem;
        for(int j = 0; j< dayNum; j++ )
        {
            /*最高每日最高气温*/
            if(myWeatherStruct[j].highestTem > dayHighestTem)
            {
                dayHighestTem = myWeatherStruct[j].highestTem;
                highPos = j;
            }
            /*最高每日最低气温*/
           if(myWeatherStruct[j].lowestTem < dayLowestTem)
		   {
			   dayLowestTem = myWeatherStruct[j].lowestTem;
			   lowPos = j;
		   }
            
            /*每日最高气温总和*/
            highestSum += myWeatherStruct[j].highestTem;

            /*每日最低气温总和*/
            lowestSum += myWeatherStruct[j].lowestTem;
          
            /*删除“转”、“～”之后的字符串*/
            stateWeather = myWeatherStruct[j].weatherState;
			for(int k=0; k < stateWeather.length();k++)
			{
				if(!(strncmp(&stateWeather[k],"转",2)) || stateWeather[k] == '~')
				{
					stateWeather = stateWeather.substr(0,k);
					break;
				}
			}
			myWeatherStruct[j].weatherState = stateWeather;
			
			dirWind = myWeatherStruct[j].windDir;
			for(int k=0; k < dirWind.length(); k++)
			{
				if(!(strncmp(&dirWind[k],"转",2)) || dirWind[k] == '~')
				{
					dirWind = dirWind.substr(0,k);
					break;
				}
			}
			myWeatherStruct[j].windDir = dirWind;

			levWind = myWeatherStruct[j].windLev;
			for(int k=0; k < levWind.length(); k++)
			{
				if(!(strncmp(&levWind[k],"转",2)) || levWind[k] == '~')
				{
					levWind = levWind.substr(0,k);
					break;
				}
			}
			myWeatherStruct[j].windLev = levWind;
			

			/*统计各种状态对应的天数*/
			if(myWeatherStruct[j].weatherState == "晴")
			{
				nwQing++;
			}

			if(myWeatherStruct[j].weatherState == "阴")
			{
				nwYin++;
			}

			if(myWeatherStruct[j].weatherState == "多云")
			{
				nwDuoyun++;
			}

			if(myWeatherStruct[j].weatherState == "小雨")
			{
				nwXiaoyu++;
			}

			if(myWeatherStruct[j].weatherState == "中雨")
			{
				nwZhongyu++;
			}

			if(myWeatherStruct[j].weatherState == "阵雨")
			{
				nwZhenyu++;
			}

			if(myWeatherStruct[j].weatherState == "雷阵雨")
			{
				nwLeizhenyu++;
			}

			if(myWeatherStruct[j].weatherState == "大雨")
			{
				nwDayu++;
			}

			if(myWeatherStruct[j].weatherState == "雨夹雪")
			{
				nwYujiaxue++;
			}

			if(myWeatherStruct[j].weatherState == "小雪")
			{
				nwXiaoxue++;
			}

			if(myWeatherStruct[j].weatherState == "暴雨")
			{
				nwBaoyu++;
			}

			if(myWeatherStruct[j].weatherState == "雷雨")
			{
				nwLeiyu++;
			}
			
			if(myWeatherStruct[j].windDir == "东南风")
			{
				nfDongnan++;
			}

			if(myWeatherStruct[j].windDir == "东风")
			{
				nfDong++;
			}

			if(myWeatherStruct[j].windDir == "西风")
			{
				nfXi++;
			}

			if(myWeatherStruct[j].windDir == "南风")
			{
				nfNan++;
			}

			if(myWeatherStruct[j].windDir == "北风")
			{
				nfBei++;
			}

			if(myWeatherStruct[j].windDir == "西南风")
			{
				nfXinan++;
			}

			if(myWeatherStruct[j].windDir == "西北风")
			{
				nfXibei++;
			}

			if(myWeatherStruct[j].windDir == "东北风")
			{
				nfDongbei++;
			}

			if(myWeatherStruct[j].windDir == "微风")
			{
				nfWeifeng++;
			}
			
			if(myWeatherStruct[j].windLev == "小于3级")
			{
				nlLes3++;
			}

			if(myWeatherStruct[j].windLev == "3-4级")
			{
				nl3to4++;
			}

			if(myWeatherStruct[j].windLev == "4-5级")
			{
				nl4to5++;
			}
        }

        aveHighestTem = (float)highestSum/dayNum;
        aveLowestTem = (float)lowestSum/dayNum;

        outFile<<"最高每日最高气温:"<<dayHighestTem<<"\t"<<myWeatherStruct[highPos].date<<"\n";
        cout<<"最高每日最高气温："<<dayHighestTem<<"\t"<<myWeatherStruct[highPos].date<<"\n";
        outFile<<"最低每日最高气温:"<<dayLowestTem<<"\t"<<myWeatherStruct[lowPos].date<<"\n";
        cout<<"最低每日最高气温："<<dayLowestTem<<"\t"<<myWeatherStruct[lowPos].date<<"\n";
        outFile<<"平均每日最高气温："<<aveHighestTem<<endl;
        cout<<"平均每日最高气温："<<aveHighestTem<<endl;
        outFile<<"平均每日最低气温："<<aveLowestTem<<endl<<endl;
        cout<<"平均每日最低气温："<<aveLowestTem<<endl<<endl;

		outFile<<"天气状态统计："<<endl;
		cout<<"天气状态统计："<<endl;

		outFile<<"晴： "<<nwQing<<endl;
		cout<<"晴： "<<nwQing<<endl;
		outFile<<"阴： "<<nwYin<<endl;
		cout<<"阴： "<<nwYin<<endl;
		outFile<<"多云： "<<nwDuoyun<<endl;
		cout<<"多云： "<<nwDuoyun<<endl;
		outFile<<"小雨： "<<nwXiaoyu<<endl;
		cout<<"小雨： "<<nwXiaoyu<<endl;
		outFile<<"中雨： "<<nwZhongyu<<endl;
		cout<<"中雨： "<<nwZhongyu<<endl;
		outFile<<"阵雨： "<<nwZhenyu<<endl;
		cout<<"阵雨： "<<nwZhenyu<<endl;
		outFile<<"大雨： "<<nwDayu<<endl;
		cout<<"大雨： "<<nwDayu<<endl;
		outFile<<"雨夹雪： "<<nwYujiaxue<<endl;
		cout<<"雨夹雪： "<<nwYujiaxue<<endl;
		outFile<<"小雪： "<<nwXiaoxue<<endl;
		cout<<"小雪： "<<nwXiaoxue<<endl;
		outFile<<"暴雨： "<<nwBaoyu<<endl;
		cout<<"暴雨： "<<nwBaoyu<<endl;
		outFile<<"雷雨： "<<nwLeiyu<<endl;
		cout<<"雷雨： "<<nwLeiyu<<endl;
		outFile<<"雷阵雨： "<<nwLeizhenyu<<endl<<endl;
		cout<<"雷阵雨： "<<nwLeizhenyu<<endl<<endl;
		
		outFile<<"风向统计："<<endl;
		cout<<"风向统计："<<endl;

		outFile<<"东风： "<<nfDong<<endl;
		cout<<"东风： "<<nfDong<<endl;
		outFile<<"西风： "<<nfXi<<endl;
		cout<<"西风： "<<nfXi<<endl;
		outFile<<"南风： "<<nfNan<<endl;
		cout<<"南风： "<<nfNan<<endl;
		outFile<<"北风： "<<nfBei<<endl;
		cout<<"北风： "<<nfBei<<endl;
		outFile<<"东南风： "<<nfDongnan<<endl;
		cout<<"东南风： "<<nfDongnan<<endl;
		outFile<<"东北风： "<<nfDongbei<<endl;
		cout<<"东北风： "<<nfDongbei<<endl;
		outFile<<"西南风： "<<nfXinan<<endl;
		cout<<"西南风： "<<nfXinan<<endl;
		outFile<<"西北风： "<<nfXibei<<endl;
		cout<<"西北风： "<<nfXibei<<endl;
		outFile<<"微风： "<<nfWeifeng<<endl<<endl;
		cout<<"微风： "<<nfWeifeng<<endl<<endl;

		outFile<<"风力统计："<<endl;
		cout<<"风力统计："<<endl;

		outFile<<"小于3级： "<<nlLes3<<endl;
		cout<<"小于3级： "<<nlLes3<<endl;
		outFile<<"3-4级： "<<nl3to4<<endl;
		cout<<"3-4级： "<<nl3to4<<endl;
		outFile<<"4-5级： "<<nl4to5<<endl;
		cout<<"4-5级： "<<nl4to5<<endl;
    }
    outFile.close();
    
    system("pause");
    return 0;
}
