// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenNovaDialogueAdapter.generated.h"

/**
 * UAshenNovaDialogueAdapter
 * Manages synchronized dialogue callouts between Kaelen and Serafina during the Empathic Conduit Nova finisher.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNovaDialogueAdapter : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenNovaDialogueAdapter();
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Narrative")
	void TriggerNovaSynchronizedBark(bool bIsFinisherApex);
};
