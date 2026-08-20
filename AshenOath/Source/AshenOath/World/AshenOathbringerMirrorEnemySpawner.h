// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenOathbringerMirrorEnemySpawner.generated.h"

/**
 * UAshenOathbringerMirrorEnemySpawner
 * World subsystem spawning the corrupted Oathbringer Mirror phantom in Mindscape when an oath is broken.
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerMirrorEnemySpawner : public UWorldSubsystem
{
	GENERATED_BODY()
public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bMirrorPhantomActive = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	bool SpawnOathbringerMirrorPhantom(FVector SpawnLocation);
};
