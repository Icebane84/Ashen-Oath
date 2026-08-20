// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenVerticalSliceMasterDirectorSubsystem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnVerticalSliceLoopCompletedSignature, bool, bLoopSuccess);

/**
 * UAshenVerticalSliceMasterDirectorSubsystem
 *
 * World Subsystem driving the continuous vertical slice game loop across combat, psychological state, and narrative progression.
 */
UCLASS()
class ASHENOATH_API UAshenVerticalSliceMasterDirectorSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|VerticalSlice")
	bool TriggerVerticalSlicePass(AActor* PlayerActor, AActor* TargetEnemyActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|VerticalSlice|Events")
	FOnVerticalSliceLoopCompletedSignature OnVerticalSliceCompleted;
};
