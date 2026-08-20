// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VFX/AshenShadowMarkVFXTypes.h"
#include "AshenKaelenShadowMarkVFXComponent.generated.h"

/**
 * UAshenKaelenShadowMarkVFXComponent
 * Drives NS_KaelenShadowMarkSeepage parameter bindings, forearm socket tracking (SOCKET_ShadowMark_LeftForearm), and vertex normal offsets.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenKaelenShadowMarkVFXComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenKaelenShadowMarkVFXComponent();
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Ashen Oath | VFX")
	FName ForearmSocketName = FName(TEXT("SOCKET_ShadowMark_LeftForearm"));

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | VFX")
	EShadowSeepagePhase CurrentPhase = EShadowSeepagePhase::Dormant;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	EShadowSeepagePhase EvaluateSeepagePhase(float CorruptionScalar);

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | VFX")
	float CalculateNormalOffset(float CorruptionScalar) const;
};
