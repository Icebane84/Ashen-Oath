// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenLorekeeperMemoryBeaconActor.generated.h"

/**
 * AAshenLorekeeperMemoryBeaconActor
 * In-world and Mindscape interactive beacon archiving resolved psychic echoes into the field journal lorekeeper database.
 */
UCLASS()
class ASHENOATH_API AAshenLorekeeperMemoryBeaconActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenLorekeeperMemoryBeaconActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Lorekeeper")
	bool bIsBeaconIgnited = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Lorekeeper")
	bool IgniteMemoryBeacon(FName EchoID);
};
