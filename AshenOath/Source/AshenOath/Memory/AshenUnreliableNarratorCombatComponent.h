// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenUnreliableNarratorCombatComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMirageFoeSpawned, FVector, SpawnLocation);

/**
 * UAshenUnreliableNarratorCombatComponent
 * Spawns phantom mirage foes and false attack telegraphs that vanish upon strike.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenUnreliableNarratorCombatComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenUnreliableNarratorCombatComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Combat")
	FOnMirageFoeSpawned OnMirageFoeSpawned;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	int32 ActivePhantomCount = 0;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Combat")
	int32 ActiveMirageCount = 0;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool SpawnCombatMirage(FVector Position);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Combat")
	bool SpawnPhantomEnemyVisual(FVector Position, float Duration = 3.0f);
};
