// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenInnerWorldTypes.h"
#include "AshenMemoryBattleComponent.generated.h"

/**
 * UAshenMemoryBattleComponent
 * Component managing psychic Memory Battles in the Inner World of Oathbringer, unlocking abilities upon memory integration.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenMemoryBattleComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenMemoryBattleComponent();

	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Memory Battle")
	FOnMemoryBattleCompleted OnMemoryBattleCompleted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Memory Battle")
	bool bMemoryBattleActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	void InitiateMemoryBattle(FAshenMemoryBattleDefinition BattleDef);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Memory Battle")
	void ResolveMemoryBattle(FName MemoryID, bool bVictory);
};
