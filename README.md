"#CPP" 

S:\Learnings\C-C++\github.com (master) 
λ g++ -O0 -std=c++17 BenchmarkTest.cpp -o benchO0               
                                                                                   
S:\Learnings\C-C++\github.com (master)                          
λ g++ -O1 -std=c++17 BenchmarkTest.cpp -o benchO1               
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ g++ -O2 -std=c++17 BenchmarkTest.cpp -o benchO2               
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ g++ -O3 -std=c++17 BenchmarkTest.cpp -o benchO3               
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ g++ -Os -std=c++17 BenchmarkTest.cpp -o benchOs               
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ g++ -Ofast -std=c++17 BenchmarkTest.cpp -o benchOfast         
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ .\benchO0.exe                                                 
Elapsed: 17488                                                  
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ .\benchO1.exe                                                 
Elapsed: 1114                                                   
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ .\benchO2.exe                                                 
Elapsed: 910                                                    
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ .\benchO3.exe                                                 
Elapsed: 965                                                    
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ .\benchOs.exe                                                 
Elapsed: 1048                                                   
                                                                
S:\Learnings\C-C++\github.com (master)                          
λ .\benchOfast.exe                                              
Elapsed: 925                                                    
                              
							  
Environment Variable for CL.exe

<b><ul><i>"C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Tools\MSVC\14.10.25017\bin\Hostx64\x64"</i></ul></b>
                              
 cl /O2 /EHsc BenchmarkTest.cpp
 .\BenchmarkTest.exe -> 133 ms
 
 cl /EHsc BenchmarkTest.cpp
 .\BenchmarkTest.exe -> 369 ms


