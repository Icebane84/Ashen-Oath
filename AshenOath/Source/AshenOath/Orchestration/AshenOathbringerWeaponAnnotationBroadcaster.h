// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AshenOathbringerWeaponAnnotationBroadcaster.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnWeaponAnnotationBroadcastedSignature, FText, WeaponAnnotationText, FName, UpgradeTag);

/**
 * UAshenOathbringerWeaponAnnotationBroadcaster
 *
 * Subsystem broadcasting weapon upgrade announcements & sound cues (PRS-001 Oathbringer Slice).
 */
UCLASS()
class ASHENOATH_API UAshenOathbringerWeaponAnnotationBroadcaster : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|WeaponAnnotations")
	void BroadcastWeaponAnnotation(FText AnnotationText, FName UpgradeTag);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|WeaponAnnotations|Events")
	FOnWeaponAnnotationBroadcastedSignature OnAnnotationBroadcasted;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AshenOath|WeaponAnnotations")
	int32 TotalAnnotationsBroadcasted = 0;
};
