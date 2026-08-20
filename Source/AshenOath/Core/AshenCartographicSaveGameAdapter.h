// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenCartographicSaveGameAdapter.generated.h"

/**
 * UAshenCartographicSaveGameAdapter
 * Serializes discovered regions, pin coordinates, ink revelation progress, and marginalia notes.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCartographicSaveGameAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCartographicSaveGameAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Core")
	bool SaveCartographicState(int32 TotalPins, int32 DiscoveredRegionsCount);
};
