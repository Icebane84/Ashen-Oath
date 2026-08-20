// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenWhiteFlameAuraActor.generated.h"

/**
 * AAshenWhiteFlameAuraActor
 * 3D world volumetric incandescent aura enveloping Kaelen and Serafina during the 12.0s catharsis phase.
 */
UCLASS()
class ASHENOATH_API AAshenWhiteFlameAuraActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenWhiteFlameAuraActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | WhiteFlame")
	float AuraIncandescenceGlow = 4.0f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | WhiteFlame")
	void SetAuraActive(bool bActive);
};
