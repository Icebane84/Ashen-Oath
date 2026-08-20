// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenDiegeticPromptInWorldAnnotationBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnPromptAnnotationBroadcastedSignature, FText, AnnotationText, FName, PromptStateTag);

/**
 * UAshenDiegeticPromptInWorldAnnotationBroadcaster
 *
 * Subsystem broadcasting diegetic prompt events to companions & HUD override layers (PRS-001-UI-006).
 */
UCLASS()
class ASHENOATH_API UAshenDiegeticPromptInWorldAnnotationBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PromptAnnotations")
	void BroadcastPromptAnnotation(FText AnnotationText, FName StateTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PromptAnnotations|Events")
	FOnPromptAnnotationBroadcastedSignature OnPromptAnnotationBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|PromptAnnotations")
	int32 TotalPromptAnnotationsBroadcasted = 0;
};
