// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenGuiltStitcherSutureComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSympatheticSutureSevered);

/**
 * UAshenGuiltStitcherSutureComponent
 * Component managing the Sympathetic Viscera damage reflection tether and severance callback for Guilt-Stitcher.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenGuiltStitcherSutureComponent : public UActorComponent
{
	GENERATED_BODY()
public:
	UAshenGuiltStitcherSutureComponent();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath | Guilt Stitcher")
	FOnSympatheticSutureSevered OnSympatheticSutureSevered;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Guilt Stitcher")
	bool bIsSutureActive = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Guilt Stitcher")
	float DamageReflectionRatio = 0.50f;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Guilt Stitcher")
	void EstablishSympatheticSuture();

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Guilt Stitcher")
	bool SeverSympatheticSuture();
};
