// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenCampfireSaveGameAdapter.generated.h"

/**
 * UAshenCampfireSaveGameAdapter
 * Serializes campfire kindled states and heartstone recipe unlocks to persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCampfireSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCampfireSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeCampfireSaveState(FName CampfireID, bool bIsKindled, int32 ForgedTraitsCount);
};
