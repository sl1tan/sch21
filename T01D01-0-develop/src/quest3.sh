mv door_managment_fi door_managment_files
cd door_managment_files
mkdir door_configuration door_map door_logs
mv *.conf door_configuration
mv *.log door_logs
mv *.1 door_map
cd ..
chmod +x ai_door_control.sh
bash ai_door_managment_module.sh