// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Combat/AshenPartySyncFinisherSubsystem.h"
#include "AshenFinisherSaveGameAdapter.generated.h"

/**
 * UAshenFinisherSaveGameAdapter
 * Serializes unlocked finisher mastery and lifetime sync execution counts to persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenFinisherSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenFinisherSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeFinisherStatsToSave(EAshenPartyFinisherType FinisherType, int32 LifetimeExecutions);
};
