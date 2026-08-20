// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenGarrettPsychologicalAnnotationBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGarrettAnnotationBroadcastedSignature, FText, AnnotationText, FName, TacticalTag);

/**
 * UAshenGarrettPsychologicalAnnotationBroadcaster
 *
 * Subsystem broadcasting Garrett's cynical/pragmatic audio annotations during combat (PRS-001 Garrett Slice).
 */
UCLASS()
class ASHENOATH_API UAshenGarrettPsychologicalAnnotationBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|GarrettAnnotations")
	void BroadcastGarrettAnnotation(FText AnnotationText, FName TacticalTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|GarrettAnnotations|Events")
	FOnGarrettAnnotationBroadcastedSignature OnAnnotationBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|GarrettAnnotations")
	int32 TotalAnnotationsBroadcasted = 0;
};
