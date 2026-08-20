#!/usr/bin/env python3
"""
aop_dag_runner.py - Asynchronous Operational Playbook (AOP-001) DAG Runner
Validates task dependencies, detects cycles, and simulates pipeline execution.
"""

import sys
from collections import defaultdict, deque

class DAGPipeline:
    def __init__(self):
        self.nodes = set()
        self.edges = defaultdict(list)
        self.in_degree = defaultdict(int)

    def add_task(self, task_name, dependencies=None):
        self.nodes.add(task_name)
        if task_name not in self.in_degree:
            self.in_degree[task_name] = 0
            
        if dependencies:
            for dep in dependencies:
                self.nodes.add(dep)
                self.edges[dep].append(task_name)
                self.in_degree[task_name] += 1

    def validate_and_sort(self):
        queue = deque([node for node in self.nodes if self.in_degree[node] == 0])
        sorted_order = []

        while queue:
            node = queue.popleft()
            sorted_order.append(node)

            for neighbor in self.edges[node]:
                self.in_degree[neighbor] -= 1
                if self.in_degree[neighbor] == 0:
                    queue.append(neighbor)

        if len(sorted_order) != len(self.nodes):
            raise ValueError("[ERROR] Cycle detected in AOP Task Dependency Graph!")

        return sorted_order

def main():
    print("=== [Ashen Oath AOP-001 DAG Pipeline Validator] ===")
    pipeline = DAGPipeline()

    # Define standard Phase 1-4 pipeline tasks
    pipeline.add_task("Phase1_DataContracts")
    pipeline.add_task("Phase1_FirewallValidation", ["Phase1_DataContracts"])
    pipeline.add_task("Phase2_GASAbilities", ["Phase1_FirewallValidation"])
    pipeline.add_task("Phase2_WorldActors", ["Phase1_DataContracts"])
    pipeline.add_task("Phase3_Actuators_UI_Audio", ["Phase2_GASAbilities", "Phase2_WorldActors"])
    pipeline.add_task("Phase4_SaveGameBridge", ["Phase3_Actuators_UI_Audio"])
    pipeline.add_task("Phase4_QATestSuite", ["Phase4_SaveGameBridge"])

    try:
        execution_order = pipeline.validate_and_sort()
        print("[PASS] Cycle-free DAG verified. Execution Order:")
        for idx, task in enumerate(execution_order, 1):
            print(f"  {idx}. {task}")
        print("[SUCCESS] AOP DAG validation completed.")
        sys.exit(0)
    except Exception as e:
        print(f"[FAIL] {e}")
        sys.exit(1)

if __name__ == "__main__":
    main()
