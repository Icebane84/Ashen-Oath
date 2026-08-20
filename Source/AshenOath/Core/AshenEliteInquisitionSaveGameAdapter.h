// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenEliteInquisitionSaveGameAdapter.generated.h"

/**
 * UAshenEliteInquisitionSaveGameAdapter
 * Serializes defeated Shroud Knights, Inquisitor Purifiers, and unique lore drops to persistent save game.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenEliteInquisitionSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenEliteInquisitionSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeEliteDefeatToSave(FName EliteID, bool bIsDefeated);
};
