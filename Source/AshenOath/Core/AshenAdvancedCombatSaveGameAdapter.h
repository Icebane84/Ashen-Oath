// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAdvancedCombatSaveGameAdapter.generated.h"

/**
 * UAshenAdvancedCombatSaveGameAdapter
 * Serializes total parries landed, executions performed, and unchained states triggered.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAdvancedCombatSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAdvancedCombatSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeAdvancedCombatStateToSave(int32 TotalParries, int32 TotalExecutions, int32 TotalUnchainedStates);
};
