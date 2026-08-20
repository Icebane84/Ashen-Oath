// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenSerafinaEmpathicAnnotationBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSerafinaAnnotationBroadcastedSignature, FText, AnnotationText, FName, EmpathicTag);

/**
 * UAshenSerafinaEmpathicAnnotationBroadcaster
 *
 * Subsystem broadcasting Serafina's compassionate/empathic dialogue annotations during combat (PRS-001 Serafina Slice).
 */
UCLASS()
class ASHENOATH_API UAshenSerafinaEmpathicAnnotationBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|SerafinaAnnotations")
	void BroadcastSerafinaAnnotation(FText AnnotationText, FName EmpathicTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SerafinaAnnotations|Events")
	FOnSerafinaAnnotationBroadcastedSignature OnAnnotationBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|SerafinaAnnotations")
	int32 TotalAnnotationsBroadcasted = 0;
};
