// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Narrative/AshenCartographicTypes.h"
#include "AshenCartographicDialogueAdapter.generated.h"

/**
 * UAshenCartographicDialogueAdapter
 * Manages narrative companion dialogue barks during landmark discovery and map scribing.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenCartographicDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenCartographicDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerLandmarkBark(ECartographicPinType PinType);
};
