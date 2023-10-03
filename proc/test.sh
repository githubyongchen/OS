#/bin/bash

echo "Testing with 2 children" > output.log
./proc_creation 2 >> output.log
echo "" >> output.log

echo "Testing with 4 children" >> output.log
./proc_creation 4  >> output.log
echo "" >> output.log

echo "Testing with 8 children" >> output.log
./proc_creation 8  >> output.log
echo "" >> output.log
