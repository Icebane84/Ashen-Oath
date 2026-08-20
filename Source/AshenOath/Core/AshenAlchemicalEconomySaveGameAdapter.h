// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenAlchemicalEconomySaveGameAdapter.generated.h"

/**
 * UAshenAlchemicalEconomySaveGameAdapter
 * Serializes lantern fuel level, oil inventory, and 64-sector corruption states.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenAlchemicalEconomySaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenAlchemicalEconomySaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SerializeAlchemicalStateToSave(float LanternFuel, int32 OilFlaskCount);
};
