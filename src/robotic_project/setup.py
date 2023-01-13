from setuptools import setup
from setuptools import find_packages
package_name = 'robotic_project'
submodules = 'robotic_project/utils'

setup(
    name=package_name,
    version='0.0.0',
    #packages=[package_name],
    packages=[package_name, submodules],
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='yunus',
    maintainer_email='yigityunus442@gmail.com',
    description='TODO: Package description',
    license='TODO: License declaration',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'simulation_executer = robotic_project.simulation_executer:main',
            'main_executer = robotic_project.main_executer:main',
        ],
    },
)
