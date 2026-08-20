// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNovaSaveGameAdapter.generated.h"

/**
 * UAshenNovaSaveGameAdapter
 * Serializes successful Nova executions, highest mutual trust synchronized, and max Integration Debt survived to save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNovaSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNovaSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveNovaStatistics(int32 TotalNovaExecutions, float MaxTrustAchieved);
};
